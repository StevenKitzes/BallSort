#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Ball {
public:
	enum BallColor { RED, BLUE };

	Ball();

	BallColor Color() const {return _color;}
	void output() const;
private:
	BallColor _color;
};

unsigned part(Ball aBalls[], unsigned cBalls);

int main()
{
	srand(time(NULL));
    cout << "Hello world!" << endl;

    Ball balls[7];
    unsigned ballCount = 7;

    for( unsigned i = 0; i < ballCount; i++ ) {
		balls[i].output();
    }
    cout << "Done!" << endl << endl;

    part(balls, ballCount);

    for( unsigned i = 0; i < ballCount; i++ ) {
		balls[i].output();
    }

    return 0;
}

Ball::Ball() {
	_color = static_cast<BallColor>(rand()%2);
}
void Ball::output() const {
	cout << "Ball color: " << (_color?"Blue":"Red") << endl;
}

unsigned part(Ball aBalls[], unsigned cBalls) {
	if( cBalls <= 1 ) return 0;

	Ball::BallColor start = aBalls[0].Color();

	unsigned firstOther = 0;

	//	loop until firstOther finds a color that's not the same as 'start'
	while( aBalls[firstOther].Color() == start ) {
		firstOther++;
		if(firstOther == cBalls) return 0;
	}

	for( unsigned i = firstOther; i < cBalls; i++ ) {
		if( aBalls[i].Color() == start ) {
			for( unsigned j = i; j > firstOther; j-- ) {
				Ball temp = aBalls[j];
				aBalls[j] = aBalls[j-1];
				aBalls[j-1] = temp;
			}
			firstOther++;
		}
	}

	cout << "part(...) is returning " << firstOther << endl;
	return firstOther;
}
