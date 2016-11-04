/*
 * @returns the KisaoTerm as integer
 */

int 
SedAlgorithmParameter::getKisaoIDasInt() const
{
  std::string::size_type pos = mKisaoID.find(':');
  if (pos == std::string::npos)
    pos = mKisaoID.find('_');
  
  if (pos == std::string::npos)
    return -1;
  
  std::stringstream str(mKisaoID.substr(pos+1));
  int result; str >> result;
  return result;
}
 
/*
 * Sets the KisaoId as integer
 */ 
int 
SedAlgorithmParameter::setKisaoID(int kisaoID)
{
  std::stringstream str; 
  str << "KISAO:" 
      << std::setfill('0') 
      << std::setw(7)
      << kisaoID; 
  mKisaoID = str.str();
  return LIBSEDML_OPERATION_SUCCESS;
}