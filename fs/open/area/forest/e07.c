inherit ROOM;

void create()
{
	set("short","野人村");
	set("long",@LONG
周圍圍繞著茂密的樹林跟一排排的木樁，所謂的道路，也不過是
一堆爛泥所鋪設成的走道，高大的木造房屋，粗糙的裝潢，顯露出未
開化的文明，路上行走的人十分稀少，大部份身上都掛著某種動物的
骨骸。
LONG);
	set("exits",([
"north":__DIR__"e11",
"west":__DIR__"e06",
"east":__DIR__"e08",
]));
	set("outdoors",1);
	setup();
}
