inherit ROOM;
void create ()
{
  set ("short", "地下室");
  set ("long", @LONG

這是一個空曠、乾淨的地下室，屋子中央放置著一個箱子(box)。

LONG);

set("item_desc", ([ /* sizeof() == 1 */
"box" : "箱子外面貼著『禁止觸碰』的封條。
",
]));

set("search_desc", ([ /* sizeof() == 1 */
"box" : "你發現箱子怪怪的，似乎可以移動。
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"room3.c",
]));

  set("light_up", 1);
  setup();
}
void init()
{
        add_action("do_move","move");
        add_action("do_push","push");
}

int do_move(string str)
{
if(!str || str != "box")
return notify_fail("你要移動什麼?\n");
if(this_player()->query("family/family_name")=="雪蒼派"||this_player()->query("family/family_name")=="魔刀門"||
this_player()->query("family/family_name")=="魔刀莫測") {
if(this_player()->query("combat_exp")>300000) {
if(!query_temp("box_moved")) {
set_temp("box_moved",1);
message_vision("$N移動了箱子，發現箱子下面竟然出現了一個按鈕(button)。\n",this_player());
    return 1;
        }
        else {
                delete_temp("box_moved");
                message_vision("$N將箱子移回原位。\n", this_player());
                if(query("exits/down"))
                  delete("exits/down");
    return 1;
        }
        }
message_vision("你的經驗值不夠移動箱子。\n",this_player());
        return 1;
        }
message_vision("你不是雪蒼或本門弟子，所以不能移動箱子。\n",this_player());
        return 1;
}

int do_push(string str)
{
        object ob;
        ob = this_player();
        if(!query_temp("box_moved"))
                return notify_fail("按什麼呀！\n");
        else if(!str || str != "button")
                return notify_fail("你在按那裏呀？\n");
        else {
                set("exits/down","/open/gblade/room/m-room1");
      message_vision("$N將按鈕壓下，嘎～嘎～地板打開一個往下的階梯。\n",ob);
               call_out("do_close",10);
        }
        return 1;
}

void do_close()
{
        if(!query("exits/down"))
                return;
        delete("exits/down");
        tell_room(this_object(),"被人打開的地板又緩緩的自動關了起來。\n");
}
