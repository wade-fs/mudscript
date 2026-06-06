inherit ROOM;

void create ()
{
  set ("short", "天龍八部陣");
  set ("long", @LONG
這裡的地上有著一個正八邊形(picture),而這個八邊形似乎隱約透出一
股強大的神力,這股力量籠罩了整個房間,讓你有一種不寒而慄的感覺, 彷
彿一觸碰到那個圖形就會有危險。
LONG);

  set("exits", ([ /* sizeof() == 1*/
  "north" : __DIR__"aa24",
]));
}
