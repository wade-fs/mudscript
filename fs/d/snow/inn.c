// inn.c


inherit ROOM;

string look_sign(object me);

void create ()
{
  set ("short", "過去時空 飲風客棧");
  set ("long", @LONG
你現在正站在雪亭鎮南邊的一家小客棧裡﹐這家客棧雖小﹐卻是方圓
五百里內最負盛名的一家﹐客棧的主人據說是一位雲遊四海的仙人﹐如果
你的福緣深厚的話﹐也許可以在這裡遇到他。除此之外﹐來自各地的旅人
都喜歡聚集在這裡交換旅途上的見聞﹐你也可以在這裡打聽到許多有趣的
消息。靠近門口的地方有一塊烏木雕成的招牌(sign)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inn_2f",
  "east" : __DIR__"square",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : (: look_sign :),
]));
  set("valid_startroom", 1);

  setup();
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "招牌寫著﹕飲風客棧。旁邊一排小字﹕莊思啞題。\n";
	else
		return "招牌寫著﹕飲風客棧。\n";
}
