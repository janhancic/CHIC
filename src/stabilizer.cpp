typedef struct _orientation {
   float w;
   float x;
   float y;
   float z;
} orientation_t;

class Stabilizer {
   private:
      orientation_t target_vector;
      orientation_t current_vector;

   public:
      Stabilizer(orientation_t *current_vector) {
         set_current_vector(current_vector);
         set_target_vector(current_vector);
      }

      void set_target_vector(orientation_t *target_vector) {
         this->target_vector.w = target_vector->w;
         this->target_vector.x = target_vector->x;
         this->target_vector.y = target_vector->y;
         this->target_vector.z = target_vector->z;
      }
      void set_current_vector(orientation_t *current_vector) {
         this->current_vector.w = current_vector->w;
         this->current_vector.x = current_vector->x;
         this->current_vector.y = current_vector->y;
         this->current_vector.z = current_vector->z;
      }

      void calculateAdjustments() {
         orientation_t diff_vector;

         diff_vector.x = this->target_vector.x - this->current_vector.x;
         diff_vector.y = this->target_vector.y - this->current_vector.y;
         diff_vector.z = this->target_vector.z - this->current_vector.z;
      }
};
