inherit ROOM;

void create ()
{
  set ("short", "船隻殘骸");
  set ("long", @LONG
你爬上甲板上, 只見四處都是青苔及鏽爛的鐵器, 船板極為脆弱, 似乎隨時
都有整艘船解體的的可能. 這艘船擱淺的地方由於被山及樹林所遮擋, 所以在小
島的石丘上並無法探得此船.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"is14.c",
]));

  setup();
}

void init()
{
        add_action("do_search", "search");
        add_action("do_enter","enter");
}

int do_search()
{
        object who;
        who = this_player();
        tell_object(who,"\n你仔細搜索,在甲板後方發現船艙的入口.\n");
        who->set_temp("search_enter",1);
        set("exits/enter",__DIR__"b_s");
        return 1;
}
int do_enter()
{
        object who;
        who = this_player();
        if (who->query_temp("search_enter")!=1||who->query_temp("get_note")==1) return 0;
else {
        tell_object(who,"\n你鑽進船艙之中.\n\n\n");
        who->move(__DIR__"b_s");
        delete("exits/enter");
        who->delete_temp("search_enter");
        return 1;}
}
int valid_leave(object me, string dir)
{
  if (dir != "enter") {
    delete("exits/enter");
    return 1;
  }
}

