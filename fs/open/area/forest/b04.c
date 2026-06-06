inherit ROOM;
#include <ansi.h>
string f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21;

void create()
{
f1=f2=f3=f4=f5=f6=f7=f8=f9=f10=f11=f12=f13=f14=f15=f16=f17=f18=f19=f20=f21="■";
f4=HIY"⊕"NOR;

	set("short","黑森林 間帶");
	set("long","

	▕"GRN"森森"+f1+GRN"森森森森森森森"+f2+GRN"森森森森森森"+f3+GRN"森森"NOR"
	▕"GRN"森森"+f4+GRN"森森森森森森森"+f5+GRN"森森森森森森森森森"NOR"
	▕"GRN"森森森森森森"+f6+f7+f8+f9+f10+f11+f12+f13+f14+f15+f16+f17+f18+f19+NOR"
	▕"GRN"森森森森森森"+f20+GRN"森森森森森森森森森森森森森"NOR"
	▕"GRN"森森森森森森"+f21+GRN"森森森森森森森森森森森森森"NOR"

這裡似乎設有結界，很明顯的感覺到兩股不同的力量在此地抗衡著，
功\力不夠的人很容易迷失方向。
\n");
	set("objects",([
__DIR__"obj/box":1,
]));
	set("exits",([
"north":__DIR__"b01",
]));
	setup();
}
