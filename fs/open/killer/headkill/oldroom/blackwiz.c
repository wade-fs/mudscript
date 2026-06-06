#include <room.h>

inherit ROOM;

 
void create()

{
  
	set("short", "玩家議見發表室");
  
	set("long", @LONG
  
		各位...最近本派非非非非非常之冷清,
		因此希望玩家能夠多多建議一些
也歡迎暫時灌水亦可....
                       
		玩家可開始在此留言了....no idea.






看到當年的敘述，不知道你的想法是什麼？
這裡是殺手以前的交誼室，但也幾乎沒有人來。
或許\是殺手實在太弱了吧？
雖然你到目前還不知道你為何會在這裡，但是你還是到處去看看吧？
LONG);
        
	set("exits", ([ /* sizeof() == 1 */
	
		"south":__DIR__"r3",
	
///         "west":__DIR__"r0.c",
  
	]));
       
	setup();
        


//	call_other("/obj/board/killerwiz_b","???");

}

/*
int valid_leave(object me, string dir)

{
  
	if (me->query("class")!="killer" && dir=="west")
 
		return notify_fail("這是殺手的禁地!由於你沒練霸雨螫魂,				故你無法進入!\n");


	return ::valid_leave(me,dir);

}


void init()

{
  
	add_action("do_pass","pass");

}


int do_pass()

{
  
	object me;
  
	me = this_player();
  
	me->move("/open/center/room/inn");
  
	return 1;

}

*/
