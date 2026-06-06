inherit ROOM;
#include <ansi.h>
int i;
string f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21;


void create ()
{
f1=f2=f3=f4=f5=f6=f7=f8=f9=f10=f11=f12=f13=f14=f15=f16=f17=f18=f19=f20=f21="■";
f1=HIW"入"NOR;
f19=HIY"⊕"NOR;
	set("short","黑森林");
	set("long","

	▕"GRN"森森森森森森森森"NOR+f1+NOR+GRN"森森"NOR"▎
	▕"GRN"森"NOR+f2+f3+f4+f5+f6+f7+f8+f9+GRN"森森"NOR"▎
	▕"GRN"森"NOR+f10+GRN"森"NOR+f11+GRN"森森"NOR+f12+GRN"森森森森"NOR"▎
	▕"GRN"森"NOR+f13+GRN"森"NOR+f14+GRN"森森"NOR+f15+f16+f17+GRN"森森"NOR"▎
	▕"GRN"森"NOR+f18+GRN"森"NOR+f19+GRN"森森"NOR+f20+GRN"森"NOR+f21+GRN"森森"NOR"▎

一陣陣涼風，由漆黑的森林內呼蕭而出，儘管鳥啼聲十分悅耳，那灰
暗的森林卻給人一種不安的恐懼。
\n");
	set("exits",([
"north":__DIR__"f14",
"south":__DIR__"a02",
]));
	setup();
}
