inherit ROOM;

void create ()
{
  set ("short", "青石板路");
	set( "build", 50 );
  set ("long", @LONG

從大門延伸過來通往正廳的青石板路，路的兩旁種滿青松，綠柳等，風一
吹來，青松拂簷，綠柳週垂，路旁立有一石。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
石頭上印有一個手印，也不知道是誰竟然有如此的掌力，能在堅硬的石頭
上，留下這樣一個手印，手印旁邊留有幾個字。
          
	金刀門主宰趙無忌 , 女主宰無名到此一遊

",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/s-guardian" : 2,
]));
  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"g1-3.c",
  "north" : __DIR__"gblade.c",
]));

  setup();
}
void init()
{
	add_action("do_move","move");
	add_action("do_enter","enter");
}
int do_enter(string str)
{
	if(!str || str != "hole")
	return notify_fail("你想鑽什?\n");
	if(!query("stone_moved"))
	return notify_fail("看清楚 , 這裡有洞嗎 ?\n");
	message_vision("$N從小洞裡鑽了進去 !\n",this_player() );
	this_player()->move("/open/gblade/room/c1-1");
	message_vision(" 碰 的一聲 , $N掉到了地下!\n",this_player());
return 1;
}
int do_move(string str)
{
	if(!str || str != "stone")
	return notify_fail("你要移動什麼 ?\n");
	if(this_player()->query_str()+this_player()->query("max_force")/10 < 150 )
	return notify_fail("你的力量不夠!\n");
	if(query("stone_moved") )
	return notify_fail("石頭已經被推開啦 !\n");
	message_vision("$N走到石頭旁 , 運功\將石頭推開 !\n",this_player() );
	message_vision("石頭被推開後 , 露出了一個小洞 !\n",this_player() );
	set("stone_moved",1);
	set("long", @LONG

從大門延伸過來通往正廳的青石板路，路的兩旁種滿青松，綠柳等，風一
吹來，青松拂簷，綠柳週垂，地上有個小洞 .

LONG);
set("item_desc", ([
"hole": "
一個天然形成的小洞 , 也許\你能鑽的進去 !
",
]));
return 1;
}
