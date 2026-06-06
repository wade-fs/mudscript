inherit ROOM;

void create()
{
  set ("short", "競技場");
  set ("long", @LONG

每半年金刀門的弟子都要在這裡互相較量一下功夫，這樣一來大家為了爭
取最高的榮譽就會努力的苦練功夫。當然了，除了本門弟子互相較量之外
如果有人要來跟金刀門的高手討教的話.....

LONG);

  set("light_up", 1 );
  set("outdoors", "/open/gblade" );
  set("valid_startroom", 0 );
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"g1-3",
]) );
  setup();
}
