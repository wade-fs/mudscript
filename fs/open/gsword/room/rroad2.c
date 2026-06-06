#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "仙劍派前山");
	set("long", "你的眼前盡是垂直的峭壁，光滑的連一根草也無法在上面著根，維獨在峭壁(cliff)的
左側，顏色較趨暗色，好奇心使你想看的清楚些，不過那高度實在太高你再怎麼努
力，也無法瞧個仔細。        
");

  set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "岩壁中唯一的裂縫,高度也較低,使勁一爬(climb),說不定爬的上去哦
",
]) );
  seteuid(getuid());

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"rroad1",
  "east" : __DIR__"rroad3",
]) );

  set("outdoors", "/open/gsword/room" );


  setup();
}

void init()
 {
 add_action("climb_cliff","climb");
 }
 int climb_cliff(string str)
 {
	string skill;
   if(str!="cliff")
  {
    return 0;
   }
//	if(!stringp(skill = this_player()->query_skill_mapped("move")))
//	{
//	message_vision("$N想爬上這陡峭的山壁，但是因為沒練輕功\而有心無力，只好放棄\n", this_player());
//	return 1;
//	}
	message_vision("$N使出"+to_chinese(skill)+"身影消失在山壁中\n",this_player());
this_player()->move(__DIR__"hole");
 return 1;
 } 
