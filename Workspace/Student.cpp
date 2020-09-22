#include <cassert>
#include <stdexcept>
#include <string>

// TODO: Define "Student" class
class Student {
 public:
  // constructor
  // accessors
  // mutators
  Student(std::string name, int grade, float GPA): name_(name) , grade_(grade), GPA_(GPA){

  }

 std::string getName(){ return name_;}
  int getGrade(){return grade_;}
  float getGPA(){return GPA_;}
// mutators

  void setName(std::string name){  
      name_ = name;
    }
  void setGrade(int grade){
          if( grade <0 || grade>12)
        throw "Invalid Input";
    grade_ = grade;

  }
  void setGPA(float gpa){
          if(gpa<0 || gpa >4.0 )
        throw "Invalid Input";
        GPA_ = gpa;
  }

 private:
  // name
  // grade
  // GPA
  std::string name_;
  int grade_;
  float GPA_;

};

// TODO: Test
int main() {
    Student s = Student("RAM",2,3.4);
    assert(s.getName()=="RAM");
    assert(s.getGrade()==2);
    assert(s.getGPA()==3.4);
    bool exceptionOccurred = false;
    try{
        s.setGrade(23);
    }
    catch(...){
        exceptionOccurred = true;
    }
    assert(exceptionOccurred);
        try{
            s.setGPA(4.8);  
        
    }
    catch(...){
        exceptionOccurred = true;
    }
    assert(exceptionOccurred);
}