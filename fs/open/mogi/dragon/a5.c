// Room: /u/p/poloer/dragon/a5
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷前段");
  set ("long", @LONG
進到了谷中，四周昏暗無光，要小心奕奕的走才行。只能摸
著牆壁前進，感覺身旁不時有東西走過，偶而還能聽到鬼怪哭嚎
的聲音，聽起來令人起寒。
    突然間牆壁上好像有些東西，可以(search)看看。

LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a2",
  "east" : __DIR__"a6",
  "west" : __DIR__"a4",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

void init()


{
    add_action("search_here", "search");


    add_action("do_dig","dig");
}




int search_here(string arg)


{








      tell_room(this_object(),"你找啊找的,發現牆上有個洞(hole)，可以挖(dig)看看
C
");


   return 1;


}








int do_dig(string str){




if(!str || str !="hole"){
                return notify_fail("你想挖哪裡？\n");
                           return 1;
                                 }
else{
tell_room(this_object(),"發現洞內有個通道。");


                set("exits/enter",__DIR__"a11");
                set_temp("have_open",1);
                 remove_call_out("do_closed");
                  call_out("do_closed",15);
                  return 1;
}
}
void do_closed()

{

        delete_temp("have_open");
        delete("exits/enter");
        tell_room(this_object(),"碰!一聲，土堆坍了洞口又關起來。\n");
}
