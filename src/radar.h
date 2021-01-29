class Radar {
   public:
      Radar();
      int get_distance(void);
      
   private:
      long time_filt_prev;
      
      void init(void);
      long filter_low_pass(long value, long prev_value);
};