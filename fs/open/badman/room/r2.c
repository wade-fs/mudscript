// Room: /open/badman/room/r2

#include <room.h>
#include "/open/open.h"

inherit ROOM;

string search_bottle();

void create ()
{
  set ("short", "春流診所");
  set ("long", @LONG
這是一間小小的診所，裡面只有一張破舊的桌子和兩個堆滿瓶
瓶罐罐的櫥櫃(cupboard)。一大堆不知名的藥材堆放在房間四周的
地板上，不識貨的人還以為這裡是個柴房呢。你看到桌子上放著厚
厚的一疊筆記(note)，大概萬神醫又在做什麼研究了吧。
    牆上掛著一張營業項目表(list)。
    你注意到西邊有一扇木製的門。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r4",
  "north" : __DIR__"r3",
  "south" : __DIR__"b10",
]));

  set("item_desc", ([ /* sizeof() == 2 */
  "note" : "筆記上寫了密密麻麻的文字和一堆奇怪的符號，這大概是萬神醫苦心研究\n的成果吧，只可惜你都看不懂。\n",
  "cupboard" : "在這個舊舊的櫃子上放了一些繃帶和傷藥，另外還有許\多大大小小的罐子(bottle)。\n",
  "list" : "\n\t營業項目      收費標準\n\n\t療傷(外傷)    一兩銀子/每點氣\n\t止血          五兩銀子/每回合\n\t解毒          五兩銀子/每回合(蛇毒)\n\t              二兩金子/每回合(天冰奇毒)\n\n",
]));

  set("search_desc", ([ /* sizeof() == 1 */
  "bottle" : (: search_bottle :),
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/one" : 1,
]));

  set("light_up", 1);

  create_door("west", "木門", "east", DOOR_CLOSED);
  setup();
}

string search_bottle()
{
	object who = this_player();

	if( who->query_temp("get_pill") )
		return "當你想再偷拿一顆的時候，突然感覺到背後似乎有雙眼睛在盯著你，\n於是趕快把手收了回去。\n";
	who->set_temp("get_pill", 1);
	if( random(2) )
		new(BAD_OBJ"s_pill")->move(who);
	else
		new(BAD_OBJ"f_pill")->move(who);
	return "你趁著大家不注意，趕緊偷偷從罐子裡摸了顆藥丸出來，藏在口袋裡。\n";
}
