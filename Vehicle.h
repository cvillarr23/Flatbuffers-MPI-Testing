




class Vehicle : public Agent {
  private:

    int posX;
    int posY;
    int posZ;
    int rank;

  public:
    Vehicle(std::string name, int x, int y, int z, int rank)
    : x(x), y(y), z(z), rank(rank) {}

    int getX() {return posX}
    int getY() {return posY}
    int getZ() {return posZ}
    int getRank() {return rank}
    int setPos(int x, int y, int z) {
      posX = x;
      posY = y;
      posZ = z;
    }

    int update() {}
}
