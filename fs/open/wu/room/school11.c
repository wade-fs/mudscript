// Room: /u/d/devils/school11.c

inherit ROOM;

void create()
{
        set("short", "藏寶庫");
        set("long", @LONG
這是一間倉庫，堆滿了雜七雜八的物品，你放眼望去似乎沒有任何
稍有價值的東西，這裡的地板很乾淨，不像一般倉庫滿地灰塵，左邊角
落有一個不起眼的箱子。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"school8",
]));
        set("light_up", 1);
        setup();
}
/*
void init()
{
        add_action("do_move","move");
        add_action("do_push","push");
}

int do_move(string str)
{
        if(!str || str != "box")
                return notify_fail("你要移動什麼?\n");
        else if(!query_temp("box_moved")) {
                set_temp("box_moved",1);
                message_vision("$N把箱子移向旁邊，赫然發現箱子下面竟然出現了一個暗門。\n", this_player());
        }
        else {
                delete_temp("box_moved");
                message_vision("$N把箱子移回原位。\n", this_player());
                if(query("exits/down"))
                        delete("exits/down");
        }
        return 1;
}

int do_push(string str)
{
        object ob;
        ob = this_player();

        if(!query_temp("box_moved"))
                return notify_fail("推什麼推！不要亂推好不好！\n");
        else if(!str || str != "door")
                return notify_fail("你在推什麼?\n");
        else {
                set("exits/down",__DIR__"school12");
                message_vision("$N緩緩的把暗門推開，這才發現原來有一個往下的階梯。\n", ob);
                call_out("do_close",10);
        }
        return 1;
}

void do_close()
{
        if(!query("exits/down"))
                return;
        delete("exits/down");
        tell_room(this_object(),"被人打開的暗門又緩緩的自動關了起來。\n");
}
*/
