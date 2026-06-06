// /open/killer/ninja/room/sea02.c
inherit ROOM;

void create()
{  
   
   set("short","汪洋大海");
   set ("long", @LONG


	恭喜，你已經正式進入第二階段的解謎，
	但是小渡還沒有完成第二階段的部分，所以到此為止
	如果你可以使用清風術，就代表你完成第一階段
	以後可以直接由第二部分開始解謎.........
	前三名看到這一段訊息的玩家，再小渡寫出第二階段之前
	會特別幫你們『暫時』把分功化影身法，強化到100級
	第一位密碼： Killer number one
	第二位密碼： I love my killer
	第三位密碼： Killer is the best
	看到這一段畫面，請抓自己的密碼後，post再版上即可	
	
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"sea01.c",
        "west" : __DIR__"sea03.c",
]));
//set("objects", ([ /* sizeof() == 1 */
//      "/open/killer/sea/npc/bunk_fish.c":1,
//      "/open/killer/sea/npc/hake_fish.c":1,
// ]));

 setup();
}

int valid_leave(object me, string dir)
{
  int max;
 object ob2;

 if ( !present("static_water",this_player()) )  //檢查玩家是否有定水珠
 {//如果沒有定水珠，代表無法在水中移動
	   message_vision("$N居然沒了定水珠，完蛋了！！.........\n",me);
	   message_vision("$N在海中漂流........\n", me);
	   me->add("kee",-20);
	   return 0;
}  
 //如果有定水珠就代表可以通過
 if (dir == "west")
 {
   if (!me->query_temp("wind"))
      return notify_fail("你被東瀛神風阻擋住，無法前進 \n");
   if (!me->query("ninja/firstpart"))
      return notify_fail("奇怪，沒解過第一階段，你怎麼學到清風術？ \n");
   if (!me->query_temp("secondpart"))
      me->set_temp("secondpart",1);
   me->add("kee",-10);
   return 1;
 }
return 1;
}
