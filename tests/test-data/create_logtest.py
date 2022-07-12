# -*- coding: utf-8 -*-
"""
Created on Wed Mar 10 14:58:01 2021

@author: Lucian
"""

import tellurium as te
import phrasedml
import libsedml
import sys
import os

r = te.loada("""
   model case_02
       species S1=10, S2=5, S3=2
       S1 -> S2; S1*k1
       S2 -> S3; S2*k2
       k1 = 0.3
       k2 = 0.2
   end
   """)

SBML = r.getSBML()
te.saveToFile("case_02.xml", SBML)

p_str = """
    model0 = model "case_02.xml"
    model1 = model model0 with S1=5+3
    
    sim0 = simulate uniform(0, 10, 10)
    task0 = run sim0 on model0
    plot "UniformTimecourse" time vs S1, S2
"""

# phrasedml.setReferencedSBML("case_01.xml", SBML)
sed = phrasedml.convertString(p_str)
if sed is None:
    print(phrasedml.getLastError())
    sys.exit()

sedml = libsedml.readSedMLFromString(sed)

plot = sedml.getOutput(0)
axis = plot.createXAxis();
axis.setType("log10")
axis = plot.createYAxis();
axis.setType("linear")
axis = plot.createRightYAxis();
axis.setType("log10")

curve = plot.getCurve(0)
curve.setType(libsedml.SEDML_CURVETYPE_POINTS)
curve.setOrder(2)
curve.unsetLogX()
curve.unsetLogY()
curve = plot.getCurve(1)
curve.setType(libsedml.SEDML_CURVETYPE_POINTS)
curve.setOrder(3)
curve.unsetLogX()
curve.unsetLogY()
curve.setYAxis("right")
curve = plot.getCurve(2)
# curve.setType(libsedml.SEDML_CURVETYPE_POINTS)
# curve.setOrder(1)
# curve.unsetLogX()
# curve.unsetLogY()


sedstr = libsedml.writeSedMLToString(sedml)
print(sedstr)

te.executeSEDML(sedstr)

sedfile = os.path.basename(__file__)
sedfile = sedfile.replace(".py", ".sedml")
sedfile = sedfile.replace("create_", "")

te.saveToFile(sedfile, sedstr)
te.saveToFile("case_01.xml", SBML)
