inherit ROOM;
 
void create ()
{
  set ("short", "巖穴入口");
  set ("long", @LONG
 前面佇立著幾個守衛，看守著這個烏七碼黑的山洞，難道這就是惡人谷傳說中的禁地?
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"s1-3",
]));

  setup();
}
