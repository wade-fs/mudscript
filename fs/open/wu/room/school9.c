// Room: /u/d/devils/school9.c

inherit ROOM;

void create ()
{
  set ("short", "夢居");
  set ("long", @LONG
這是任正晴的寢室，擺設十分簡單，只有一張床和一些簡單家俱和一只花瓶，
看似單純，卻暗藏玄機，聽說任正晴為了怕人趁他睡覺偷襲他，暗藏了許多
機關，沒事別亂闖這裡，免的死於非命！
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school8",
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
        if(!str || str != "花瓶")
                return notify_fail("你要移動什麼?\n");
        else if(!query_temp("box_moved")) {
                set_temp("box_moved",1);
                message_vision("$N移動了花瓶，此時赫然發現花瓶後面竟然出現了一個暗扣(button)。\n", this_player());
        }
        else {
                delete_temp("box_moved");
                message_vision("$N將花瓶移回原位。\n", this_player());
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
                return notify_fail("按什麼按！不要亂按好不好！\n");
        else if(!str || str != "button")
                return notify_fail("你在按那裏呀?\n");
        else {
                set("exits/down","/open/wu/room/gen1");
                message_vision("$N將暗扣按下，嘎～嘎～地板打開一個往下的階梯。\n", ob);
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
