//written by acelan...../u/a/acelan/room/wood30.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "岩頂");
        set("long", @LONG
岩頂大霧迷漫, 伸手不見五指, 四周一片沈寂, 連鳥叫蟬鳴亦聽
不到, 只能隱約的看到前方有著幾棵樹, 而地上開放著不知名的小花
, 顏色豔麗, 頗為奇特。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "down" : "/open/killer/mon/room/wood26.c",
   ]));

        set("no_clean_up", 0);

        setup();
}
void init()
{
   add_action("do_search", "search");
   add_action("do_pull", "pull");
}
int do_search( string str)
{
	if(!str)	return 0;
	if( str != "dagger")
	{
	message_vision("你找來找去, 什麼都沒有找到...\n",this_player());	
	return 0;
	}
   if( present("god dagger", this_player()))
   {
      message_vision("岩壁又開始崩塌.......你從岩壁上摔下去了...\n",this_player());
      
      this_player()->add("kee", -100);
      this_player()->move("/open/killer/mon/room/wood26.c");
      return 0;
   }
   if( this_player()->query("quest/rain")==1)  //再檢查一次, 避免當官的殺手帶人來
   {
      message_vision("經過你仔細的搜索之後, 赫然發現地上插著一隻匕首(dagger)...\n",this_player());
      message_vision("它看起來就像是失落已久的" + HIW + "滅神匕首" + NOR + "....\n",this_player());
      message_vision("你可以試著將它拔起(pull)。\n",this_player());
      return 1;
   }
}
int do_pull(string str)
{
   object ob_dagger;
   if( str == "dagger")
   {
      if( present("god dagger", this_player()))
      {
         message_vision("岩壁又開始崩塌.......你從岩壁上摔下去了...\n",this_player());
         this_player()->add("kee", -100);
         this_player()->move("/open/killer/mon/room/wood26.c");
         return 0;
      }
      if( this_player()->query("quest/rain")!=1)
      {
         message_vision("哪來的 dagger 給你拉..............\n",this_player());
         return 0;
      }
      message_vision("..........................................\n",this_player());
      message_vision("你很用力的將" + HIW + "滅神匕首" + NOR + "拔了起來....\n",this_player());
      message_vision("突然間山搖地動, 剛才的舉動似乎引起了山崩。\n",this_player());
      message_vision("果然....你從岩壁上摔下去了................\n",this_player());

      ob_dagger= new("/open/killer/obj/dagger.c");
      ob_dagger->move(this_player());
      this_player()->move("/open/killer/mon/room/wood26.c");
      return 1;
   }
   else
   {
      message_vision("你要拉什麼...........\n",this_player());
      return 0;
   }
}
