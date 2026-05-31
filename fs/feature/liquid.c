// liquid.c

#include <dbase.h>
#include <name.h>

varargs string long(int raw)
{
	int amount, max;
	string str;

	if( amount = query("液體/剩") ) {
		str = query("long");
		max = query("飽和");
		if( amount == max )
			str += "裡面裝滿了" + query("liquid_name") + "\n";
		else if( amount > max/2 )
			str += "裡面裝了七、八分滿的" + query("liquid_name") + "\n";
		else if( amount >= max/3 )
			str += "裡面裝了五、六分滿的" + query("liquid_name") + "\n";
		else if( amount > max/4 )
			str += "裡面裝了少許\的" + query("liquid_name") + "\n";
		return str;
	}
	else return query("long");
}
