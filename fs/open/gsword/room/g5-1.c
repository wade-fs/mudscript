// Room: /open/gsword/room/g5-1.c
inherit ROOM;

void create ()
{
  set ("short", "仙劍凌霄寶殿");
	set( "build", 30 );
  set ("long", @LONG
這裡就是天下劍士總本部。殿中一張太師椅，一個白髮鬚鬚的老者正
高坐其上。凌霄寶殿雖位於仙劍派中，但因其是劍士公會的所在，因此裝
璜的金壁輝黃，迥異於其它仙劍劍築，四隻金龍衝天而起，分立四方。近
年來由於仙劍的興起，劍道成為武學主流，凌霄寶殿也儼然成為武林總部
。大殿的左後方有個招牌(sign)。左邊的牆上掛著一張羊皮(paper) 寫著
仙劍武術的簡介。
 
LONG);
  set("item_desc", ([ /* sizeof() == 2 */
  "sign" : "招牌上寫著:
欲辦理加盟劍士公會手續者 ,請在蜀中連絡處就近辦理 ,本總部恕不受理 .\n",
 "paper" :" 欲知仙劍武學，請鍵入help shasword\n",
  ]));
  set("exits",([ /* sizeof() == 5 */
  "up" : "/open/gsword/room/eqroom.c",
  "west" : "/open/gsword/room/g4-10.c",
  "south" : "/open/gsword/room/g4-2",
  "north" : "/open/gsword/room/g5-2.c",
  "east" : "/open/gsword/room/g5-8.c",
]));

  set("light_up", 1);

  set("no_fight", 0);

  set("objects", ([ /* sizeof() == 1 */
   "/daemon/class/swordsman/master" :1,
]));

   set("valid_startroom", 1);

  setup();
  call_other("/obj/board/swordsman_b","????");
}

 int valid_leave(object me, string dir)
{
if( dir=="up" )
if( me->query("family/family_name")!="仙劍派"
	&& !wizardp(me) )
   return notify_fail("只有仙劍門徒才能進入\n");
return ::valid_leave(me,dir);
 }
