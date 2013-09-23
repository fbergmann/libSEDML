  /** 
   * @return the number of items
   */
  unsigned int SedVectorRange::getNumValues() const
  {
    return mValues.size();
  }
  
  /**
   * @return the value at the given index, or NaN.
   */
  double SedVectorRange::getValue(unsigned int index) const
  {
    if (index > mValues.size())
      return numeric_limits<double>::quiet_NaN();
    return mValues[index];
  }
  
  /**
   * clears the vector of values
   */
  void SedVectorRange::clearValues()
  {
    mValues.clear();
  }
  
  /** 
   * adds the given value
   */ 
  void SedVectorRange::addValue(double value)
  {
    mValues.push_back(value);
  }
  
  /**
   * removes the item at the given index and returns it
   */
  double SedVectorRange::removeValueAt(unsigned int index)
  {
    std::vector<double>::iterator it = mValues.begin() + index;
    if (it == mValues.end())
      return numeric_limits<double>::quiet_NaN();
    double result = *it;
    mValues.erase(it);
    return result;
  }
  
  /**
   * sets the value at the given index
   */ 
  void SedVectorRange::setValue(unsigned int index, double value)
  {
    if (index > mValues.size())
     return;
    mValues[index] = value;
  }
  