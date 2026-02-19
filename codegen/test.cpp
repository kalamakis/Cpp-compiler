class takos {
   public:
      int gamato;
      int foo1();
};

int takos::foo1() {
   return 1;
}

int main() {
   int x;
   takos my_class;
   takos my_classs;

   x = my_class.gamato; 
}