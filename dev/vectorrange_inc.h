
protected:

  std::vector<double> mValues;

public: 

  /** 
   * @return the number of items
   */
  unsigned int getNumValues() const;
  
  /**
   * @return the value at the given index, or NaN.
   */
  double getValue(unsigned int index) const;
  
  /**
   * clears the vector of values
   */
  void clearValues();
  
  /** 
   * adds the given value
   */ 
  void addValue(double value);
  
  /**
   * removes the item at the given index and returns it
   */
  double removeValueAt(unsigned int index);
  
  /**
   * sets the value at the given index
   */ 
  void setValue(unsigned int index, double value);  
  

