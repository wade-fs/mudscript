// Room: /u/s/sueplan/newplan/area/get3.c
inherit ROOM;

void create ()
{
  set ("short", "小橋邊");
  set ("long", @LONG

天空泛著白雲, 看起來天氣是非常的和煦, 路上可以聽到鳥兒
高聲歌唱, 讓你的心情無比的愉快。眼前是一座小橋, 橋身橫過清
澈的水面, 水中還可以看到小魚游匿哩!!

LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"groom4.c",
]));

  setup();
}
void init()
{
add_action("do_take","take");
add_action("do_search","search");
}
int do_take(string str)
{
object me=this_player();
object ob;
if(str=="boots")
{
if(me->query_temp("can_get")==1)
        {
        message_vision("$N撈呀撈的, 一個小鞋被$N撈起來了\n",me);
        ob=new("/open/scholar/room/newplan/obj/qboots");
        ob->move(me);
        }
        else
        {
        message_vision( "$N要拿什麼??$N不知道吧??\n",me);
        }
if(me->query_temp("get_boots")==3)
        {
        message_vision("$N撈夠了吧???\n",me);
        }
return 1;
}
}
int do_search(string arg)
{
        object me;
        me = this_player();
        tell_object(me,"你看到一個青色的小鞋在橋下, 你應該可以撈到(take boots)吧\n");
        return 1;
}
