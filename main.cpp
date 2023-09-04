/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(float v, const char* str) : value(v), name(str) {}  //1
    float value; //2
    std::string name; //3
};

struct CompareFunction                               //4
{
    T* compare(T* a, T* b) //5
    {
        if( a != nullptr)
        {
            if( b != nullptr)
            {
                if( a->value < b->value ) return a;
                if( a->value > b->value ) return b;
            }
        }
        return nullptr;
    }
};

struct U
{
    float var1 { 0.0 }, var2 { 0.0 };
    float multiply(float* updatedValue)      //12
    {
        if( updatedValue != nullptr)
        {
            std::cout << "U's var1 value: " << this->var1 << std::endl;
    
            this->var1 = *updatedValue;
    
            std::cout << "U's var1 updated value: " << this->var1 << std::endl;
    
            while( std::abs(this->var2 - this->var1) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                this->var2 += 0.001f;
            }
            std::cout << "U's var2 updated value: " << this->var2 << std::endl;
        }
        return this->var2 * this->var1; 
    }
};

struct Calculator
{
    static float multiply(U* that, float* newValue)        //10
    {
        if( that != nullptr)
        {
            if(newValue != nullptr)
            {
                std::cout << "U's var1 value: " << that->var1 << std::endl;
                that->var1 = *newValue;
                std::cout << "U's var1 updated value: " << that->var1 << std::endl;
                
                while( std::abs(that->var2 - that->var1) > 0.001f )
                {
                    /*
                     write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                     */
                    that->var2 += 0.001f;
                }
                std::cout << "U's var2 updated value: " << that->var2 << std::endl;
            }
        }
        return that->var2 * that->var1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(4.5f, "T1");                                             //6
    T t2(3.5f, "T2");                                             //6
    
    CompareFunction f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "Error! The compare function has returned a nullptr due to the result being equal values. This could change further if alternative conditionals are implemented into the function." << std::endl;
    }

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Calculator::multiply(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.multiply(&updatedValue) << std::endl;
}