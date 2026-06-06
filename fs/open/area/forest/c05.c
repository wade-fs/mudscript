inherit ROOM;
#include <ansi.h>
string c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16;

void create()
{
c1=c2=c6=c7=c8=c9=c10=c11=c12=c13=c14=c15=c16=HIW"■"NOR;
c3=GRN"■"NOR;
c4=c5=HIC"::"NOR;
c5=NOR+HIY"⊕"NOR;

	set("short",HIM"桃花源 入口"NOR);
	set("long","

	"GRN"森"HIW"▕▎"HBBLU+HIW"~~~~~~~~"NOR+c1+HBBLU+HIW"~~~~"NOR+HIG"草草"NOR"
	"GRN"森"HIW"▕▎"HIG"草草草草"+c2+YEL"屋"HIG"草草草"NOR"
	"+c3+c4+c5+c6+c7+c8+c9+c10+c11+c12+c13+c14+NOR"
	"GRN"森"HIW"▕▎"HIG"草草草草"+c15+YEL"屋"HIG"草草草"NOR"
	"GRN"森"HIW"▕▎"HIG"草草草草"+c16+HIG"草草草草"NOR"

一股桃花香撲鼻而來，你四處可以聽到幼童的遊樂聲與老翁們的交談
呢喃，真可謂是人間樂土。
\n");
	set("exits",([
"west":__DIR__"c04",
"east":__DIR__"c06",
]));
	setup();
}

int valid_leave(object me,string dir)
{
        if( dir == "west" )
        {
                if( !present("glass crystal",me) || !me->query_temp("open/forest/crystal") )
                {
                        message_vision(HIM"一股無形的氣牆擋住了$N的去路!\n"NOR,me);
                        return notify_fail(HIM"你無法通過。\n"NOR);
                }
                else
                        return 1;
        }
return 1;
}
