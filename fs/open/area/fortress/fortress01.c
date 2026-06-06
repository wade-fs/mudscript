inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","小山丘");
        set ("long",@LONG
略微隆起的，光禿禿的地面沒有生長任何樹木，這裡是唯一可以
被陽光照射的地方，在這片光禿禿的土黃色小山丘上，佇立著一面怪
異的土牆，約略一個正常成人的高度，兩手臂一張，就可以抓住土牆
的兩側，厚度約半尺，在這面土牆中央，有一個四方形的凹槽，約略
一個手掌大，似乎可以放置什麼東西。
LONG);
        set("exits",([			//設定出口
"back":__DIR__"forest01",
]));
        set("item_desc",([		//設定路標
"土牆":"土牆，約略一個正常成人的高度，兩手臂一張，就可以抓住土牆
的兩側，厚度約半尺\n",
"凹槽":"凹槽，約略一個手掌大，似乎可以放置(put)什麼東西...\n",
]));
        set("objects",([		//設定物件
__DIR__"npc/thief02":1,
__DIR__"npc/robber02":1,
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}

void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	if(arg != "token") return 0;
	
	if(!present("fortress token",this_player()))	return 0;
	else
	{
		message_vision(HIY + "\n$N將令牌放入土牆的凹槽中。\n土牆附近突然出現一個往下的通道！\n\n" + NOR,this_player());
		this_object()->add("exits",(["down":__DIR__"fortress02",]));	//增加通道
		this_object()->set("long","略微隆起的，光禿禿的地面沒有生長任何樹木，這裡是唯一可以
被陽光照射的地方，在這片光禿禿的土黃色小山丘上，佇立著一面怪
異的土牆，約略一個正常成人的高度，兩手臂一張，就可以抓住土牆
的兩側，厚度約半尺，在這面土牆中央，有一個四方形的凹槽，已放
置了令牌，在土牆附近，有一個往下的通道。\n");
	}
	destruct(present("fortress token",this_player()));
	return 1;
}

int valid_leave(object me,string dir)		//房間移動方向
{
        if(dir=="down")
        {
                if(present("thief",environment(me)) || present("robber",environment(me)))
                        return notify_fail(HIR + "極火山寨的小嘍嘍吼著：想下去！當我是死人啊！\n" + NOR);
                else
                {
                	message_vision("$N往下走入了通道內。\n$N一通過通道，周圍的沙土把往下的通道給堵住了。\n",this_player());
                	this_object()->delete("exits/down");
                	this_object()->set("long","略微隆起的，光禿禿的地面沒有生長任何樹木，這裡是唯一可以
被陽光照射的地方，在這片光禿禿的土黃色小山丘上，佇立著一面怪
異的土牆，約略一個正常成人的高度，兩手臂一張，就可以抓住土牆
的兩側，厚度約半尺，在這面土牆中央，有一個四方形的凹槽，約略
一個手掌大，似乎可以放置什麼東西。\n");
                	return 1;
                }
        }
return 1;
}
