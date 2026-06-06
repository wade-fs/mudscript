// Room: /open/capital/room/CUR.c

inherit ROOM;

void create ()
{
  set ("short", "銀針門");
  set ("long", @LONG
進到這裡，你幾乎無法想像這樣寒酸的地方竟是醫者公會—銀針門
之所在，簡單樸素的裝潢，簡陋的家具和一般的住家沒有兩樣，唯一不
同的是，這裡十分的乾淨。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"h08",
]));

 
  set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/master_ben" : 1,
]));

  set("light_up", 1);
  set("no_magic", 1);

  setup();
        call_other("/obj/board/doctor_b", "???");
}
