#include "WPILib.h"
#include <string>
#include <map>
#ifndef JOYSTICKCACHE_H
#define JOYSTICKCACHE_H
namespace CORE{

class JoystickCache{
	struct j_key{
		int joystick;
		int channel;
	    j_key( int joystick, int channel) : joystick( joystick ), channel(channel) {}
	};
	
	typedef std::map<std::string, j_key> j_map;
	typedef std::map<std::string, double> d_cache;
	typedef std::map<std::string, bool> b_cache;
public:
	Joystick joystick1;
	Joystick joystick2;
	
	j_map axes;
	j_map buttons;
	
	d_cache cached_axes;
	b_cache cached_button;
	
	JoystickCache():
			joystick1(1),
			joystick2(2){
		
	}
	void register_axis (std::string name, int joystick, int axis);
	void register_button(std::string name, int joystick, int button);
	void update_cache(void);
	double axis(std::string name);
	bool button(std::string name);
	Joystick& get_joystick(int axis);
	
	
	
};
}
#endif
