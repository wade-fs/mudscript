inherit ROOM;
void create() {
	set( "short", "魔劍室5" );
	set( "owner", "mekyn" );
	set( "object", ([
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount3"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10058 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room460",
	]) );
	set( "long", @LONG

                          |\__-----__/|
                     _____/::::::  :::\_____   
                    '__--(:::::::::..::)--__` 
                    /  _- \/: :::::::\/ -_  \
                      /   /::.   .::::\   \
                         |:::::::::::::| 
                        _|/:::::____::\|_   
                      /::/:::::/:_::\::\:.\  
                     |::|  ..:(_/ \::|::|::|
                     |::|:::::. ::|: |::|.:|
                      \:|::  :::_/::/: :|:/ 
                    ((___\____\____/___/___))


LONG);
	setup();
	replace_program(ROOM);
}
