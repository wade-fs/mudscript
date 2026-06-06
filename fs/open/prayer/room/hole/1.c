///open/prayer/room/hole/1.c

inherit ROOM;
int have=1;
void create()
{
	set("short", "石壁");
	set("long", @LONG

	傳說這裡是破邪洞窟的入口，可是除了石壁(wall)外，沒有見到所
	謂的"門"，不過在石壁的角落有一塊突出的石塊(stone)。 或許你
	願意運起內力推開(push)石壁試試.......

LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/prayer/room/westarea/road19",
]));
	set("item_desc", ([
	"wall":	"一道紅褐色的石壁，你可以嘗試著推推看。\n"
	]));
           set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/oldwoman" : 1,
]));
     set("light_up", 1);
        setup();
}

void init()
{
        add_action("search_here", "search");
	add_action("do_turn","turn");
	add_action("do_push","push");
}

int search_here(string str)
{
    if( (this_player()->query("combat_exp",1) > 50000)  && query_temp("can_pass") )
      write("你伸手向石壁上的石頭摸呀摸的,覺得這塊突起的石頭似乎有點問題.\n"+
            "你可以試著轉動轉動它(turn stone).\n");
    else
      write("也許\是你經驗不足,你什麼也沒發現...\n");
    return 1;
}
int do_turn(string str)
{
	if(!str || str != "stone")
		return notify_fail("你要轉動什麼?\n");
	else if(!query_temp("stone_turned")) {
set_temp("stone_turned",1);
message_vision("$N把石塊輕輕地轉動，赫然聽見機關運轉的聲音。\n", this_player());
	}
	else {
		delete_temp("stone_turned");
		message_vision("石塊慢慢地回到原位。\n", this_player());
		if(query("exits/enter"))
			delete("exits/enter");
	}
	return 1;
}

int do_push(string str)
{
	object ob;
	ob = this_player();

	if(!query_temp("stone_turned"))
		return notify_fail("你覺得你推的動石壁嗎??\n");
	else if(!str || str != "wall")
		return notify_fail("你在推什麼?\n");
	else {
	set("exits/enter",__DIR__"2.c");
message_vision("$N緩緩的把石壁推開，這才發現原來有一條通往洞穴的路。\n", ob);
		call_out("do_close",10);
	}
	return 1;
}

void do_close()
{
	if(!query("exits/enter"))
		return;
	delete("exits/enter");
	tell_room(this_object(),"被人推開的石壁又緩緩的自動關了起來。\n");
}
 int valid_leave(object ob, string dir)
  {
    if(dir=="enter" && !ob->query_temp("can_pass",1))
        return notify_fail("奇怪!!為什麼無法進入呢??是不是漏掉了什麼??\n");
        
   return 1;
}

