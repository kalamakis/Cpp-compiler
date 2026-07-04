
class A{
   private:
      int i[2],j[3];
   protected:
      int go(int, int &);
};

class B {
   float a,b;
};

class C : B {
   private:
      int x,y;
   protected:
      char a[40][10];
   public:
      float see, seearray[100];
      B bb;
      float mine(int,int&,float);
};

int A::go(int a, int &b){
   b=a;
   return a++;
}

float C::mine(int a, int &b, float c){
   c = a+b;
   b=a--;
   return c;
}

int main(){
   A myclassA;
   C myclassC;
   B myclassB;

   int a,b;
   float c;

   c=myclassC.mine(a,b,c);
   b=myclassA.go(a,b);
   return 0;
}
