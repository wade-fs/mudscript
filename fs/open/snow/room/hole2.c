#include <room.h>
#include "dunno.h"

inherit ROOM;

void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
這裡是洞穴的內部﹐在西面的石壁(wall)
上似乎勉強可以看到幾個字﹕
 
    「仙劍無極﹐魔刀莫測」
 
                  獨孤愁
 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hole.c",
  "up" : __DIR__"hole10",
]));

  setup();
}
void init()
{
      add_action("do_look","l");
           add_action("do_look","look");
        add_action("do_key","key");
}
int do_look(string str)
{
      if(str!="wall") return 0;
	tell_object(this_player(),"你發現牆上有一塊石板(board)。\n");
       return 1;
}
int do_key(string str)
{
	if( str != KEY_WORD+" on board" ) return 0;
		tell_object( this_player() , "結果「喀」的一聲﹐你打開了石璧的門。\n");
         tell_object(this_player(),"你進入了密室。\n");
 this_player()->move("/open/gblade/room/secret.c");
tell_room(environment(this_player()),sprintf ("%s打開石室的門，走了進來。\n",
this_player()->short()),this_player());
         return 1;
}
