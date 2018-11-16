#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool B();
bool IT();
bool IT_TAIL();
bool OT();
bool OT_TAIL();
bool AT();
bool AT_TAIL();
bool L();
bool A();

stack<char> s;
stack<bool> b;
bool B(){
 //cout << " B "<< endl;
  if (IT()){
    if (s.top()=='.'){ 
      // cout << " B ."<< endl;
      return true;
    }  
    
  }
    
    return false;
  }
  
bool IT(){
  //cout << " IT "<< endl;
  
  if (OT()){
    if (IT_TAIL()){
      return true;
       cout << " IT"<< endl;
    }
  }
     //cout << " IT false"<< endl;
     return false;
     
  }
 
bool IT_TAIL(){
  //cout << " IT_TAIL "<< endl;
  if (s.top()=='-') {
    s.pop();
    if (s.top()=='>'){
      s.pop();
      
       if (OT()){
         //cout << " OT Tail in IT Tail"<< endl;
        bool k = b.top();
        b.pop();
        bool l = b.top();
        b.pop();
        bool kl= true;
        if (k && !l){
         kl = false;
        }
        
         
      
        
        b.push(kl);
        
          if (IT_TAIL()){
           // cout << " IT TAIL after push kl"<< endl;
         
            return true;
          }
        }
      } 
    }
  else if (s.top()=='.'){
    // cout << " IT TAIL ."<< endl;
    return true;
   }
  else if (s.top()==')'){
     //cout << " IT TAIL  )"<< endl;
    return true;
  }
  cout <<  s.top() << endl;
   //cout << " IT TAIL  false"<< endl;
   
  return false;
}

bool OT(){
  //cout << " OT "<< endl;
  if (AT()){
    if (OT_TAIL()){
      //cout << " OT true"<< endl;
      return true;
    }
  }
 // cout << " OT false"<< endl;
     return false;
  }
  
bool OT_TAIL(){
  //cout << " OT_TAIL "<< endl;
  if (s.top()=='v'){
      s.pop();
       if (AT()){
         
         bool k = b.top();
            b.pop();
         bool l = b.top();
         b.pop();
        bool kl = k || l;
        b.push(kl);
        
          if (OT_TAIL()){
           // cout << " OT_TAIL"<< endl;
            return true;
          }
        }
    }
  else if (s.top()=='-'){
   char q = s.top();
    s.pop();
    if (s.top()=='>'){
      s.push(q);
      //cout << " OT_TAIL  ->"<< endl;
        return true;
   }
  }
  else if (s.top()=='.'){
   // cout << " OT_TAIL  ."<< endl;
    return true;
  }
  else if (s.top()==')'){
    //cout << " OT_TAIL  )"<< endl;
    return true;
   }
  return false;
}

bool AT(){
  //cout << " AT "<< endl;
  if (L()){
    if (AT_TAIL()){
     // cout << " AT_TAIL true "<< endl;
      return true;
    }
  }
   // cout << " AT_TAIL false "<< endl;
     return false;
  }
  
bool AT_TAIL(){
 // cout << "AT_TAIL "<< endl;
  if (s.top()=='^'){
      s.pop();
       if (L()){
         bool k = b.top();
            b.pop();
         bool l = b.top();
         b.pop();
        bool kl = k && l;
        b.push(kl);
          if (AT_TAIL()){
            //cout << "First AT_TAIL"<< endl;
            return true;
          }
        }
    }
else  if (s.top()=='-'){

    char q = s.top();
    s.pop();
    if (s.top()=='>'){
      s.push(q);
      //cout << "AT_TAIL ->"<< endl;
        return true;
   }
  }
  else if (s.top()=='v'){
   // cout << "AT_TAIL v" << endl;
    return true;
  }
  
  else if (s.top()=='.'){
    //cout << "AT_TAIL  ."<<endl;
    return true;
  }
  else if (s.top()==')'){
   // cout << "AT_TAIL ) "<< endl;
    return true;
   }
  // cout << "AT_TAIL false"<< endl;
  return false;
}

bool L(){
  //cout << " L "<< endl;
  if (A()){
   // cout << "L if A"<< endl;
    return true;
  }
  else if (s.top()=='~'){
    
    s.pop();
    
     if (L()){
    //  cout << "L ~"<< endl;
    bool  h = b.top();
    b.pop();
     h = !h;
     b.push(h);
      return true;
    }
    
  }
 // cout << "A false"<< endl;
  return false;  
}

bool A(){
//  cout << " A "<< endl;
  if (s.top()=='T'){
    b.push(true);
    s.pop();
  //  cout << "A T"<< endl;
    return true;
  }
  else if (s.top()=='F'){
    b.push(false);
    s.pop();
   // cout << "A F"<< endl;
    return true;
  }
  else if (s.top()=='(') {
    s.pop();
    if (IT()){
      if(s.top()== ')'){
        s.pop();
   //   cout << "A ture("<< endl;
      return true;
      }
    }
  }
 // cout << "A false ("<< endl;
  return false;  
}
  
   int main (){
   string str ;
   getline(cin, str);

   for(int i= 99;i>=0;i--){
       if(str[i] == ' ' && s.top() == '-'){ 
       
       cout << "Error" << endl;
       }
       else if(str[i] != ' '){
         s.push(str[i]);
       }
      //cout << "Top of the stack " << s.top() << endl;
      }
 cout << "\n" << endl;
       if (B()){
         
         cout << boolalpha << b.top() << endl; 
       }
       else  {
 cout << "Error" << endl;
       }
 
     
   }
