#include <ansi.h>

int funexp(object me,string fun,int exp)
{
int value,maxvalue,level,maxlevel;

        me = this_player();
        maxlevel = me->query("class-level/singer/level");
        level = me->query("functions/"+fun+"/level");

        if ( level < maxlevel )
        {
                me->add("functions/"+fun+"/learned",exp);
                value = me->query("functions/"+fun+"/learned");
                maxvalue = level*(level*20+21);
                if ( value >= maxvalue )
                {
                        me->set("functions/"+fun+"/learned",0);
                        me->add("functions/"+fun+"/level",1);
                        tell_object(me,HIC+"你的"+to_chinese(fun)+"進步了！\n"+NOR);
                }
        }
        return 1;
}
