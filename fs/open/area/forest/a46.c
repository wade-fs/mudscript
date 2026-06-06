inherit ROOM;
#include <ansi.h>
#include "dam.c"
string a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51;


void create()
{
a1=a2=a3=a4=a5=a6=a7=a8=a9=a10=a11=a12=a13=a14=a15=a16=a17=a18=a19=a20=a21=a22=a23=a24=a25=a26=a27=a28=a29=a30=a31=a32=a33=a34=a35=a36=a37=a38=a39=a40=a41=a42=a43=a44=a45=a46=a47=a48=a49=a50=a51=NOR + "■" + NOR;
a14=a15=HIW + "][" + NOR;
a46=NOR+HIY"⊕" + NOR;
	set("short","黑森林沼澤");
	set("long","

	▕"+BYEL+"澤"+a1+BYEL+"澤"+a2+BYEL+"澤澤"+a3+BYEL+"澤"+a4+BYEL+"澤"+HBCYN+HIW+"~~~~~~~~~~~~~~~~~~"+NOR+BYEL+"澤"+NOR+"▎
	▕"+BYEL+"澤"+a5+BYEL+"澤"+a6+BYEL+"澤澤"+a7+BYEL+"澤"+a8+HBCYN+HIW+"~~~~"+NOR+BYEL+"澤"+a9+a10+a11+a12+BYEL+"澤澤"+a13+BYEL+"澤"+NOR+"▎
	▕"+HBCYN+HIW+"~~~~~~~~~~~~"+a14+HBCYN+HIW+"~~"+a15+HBCYN+HIW+"~~"+NOR+BYEL+"澤澤"+a16+BYEL+"澤澤澤澤澤"+a17+BYEL+"澤"+NOR+"▎
	▕"+HBCYN+HIW+"~~~~~~"+NOR+BYEL+"澤澤澤"+a18+a19+a20+a21+a22+a23+a24+a25+a26+a27+a28+a29+a30+BYEL+"澤"+NOR+"▎
	▕"+HBCYN+HIW+"~~~~"+NOR+BYEL+"澤澤澤澤澤澤澤澤"+a31+BYEL+"澤澤"+a32+BYEL+"澤澤澤"+a33+BYEL+"澤澤"+NOR+"▎
	▕"+BYEL+"澤澤澤"+a34+a35+a36+a37+a38+a39+a40+a41+BYEL+"澤澤"+a42+BYEL+"澤澤澤"+a43+BYEL+"澤澤"+NOR+"▎
	▕"+BYEL+"澤澤"+a44+a45+BYEL+"澤澤澤澤澤澤"+a46+BYEL+"澤澤"+a47+BYEL+"澤澤澤"+a48+BYEL+"澤澤"+NOR+"▎
	▕"+BYEL+"澤澤"+a49+BYEL+"澤澤澤澤澤澤澤"+a50+BYEL+"澤澤澤澤澤澤"+a51+BYEL+"澤澤"+NOR+"▎

整個空氣瀰漫著陣陣的惡臭，陰暗、潮濕，讓人十分難以忍受，精氣
似乎漸漸的消逝，四周彷彿埋伏著某些生物，正虎視眈眈的窺探著過
路的人們。
\n");
	set("objects",([
__DIR__"npc/shadow":1,
]));
	set("exits",([
"north":__DIR__"a41",
"south":__DIR__"a50",
]));
setup();
}
