// ɱ by swy
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int main(object me, string arg)
{
        int i;
        int be=me->query("bellicosity");
        if( !arg ||  !sscanf(arg, "%d", i) )
        return notify_fail("O榡Rcmd killup <I>\n");
        if(me->query_skill_mapped("force")=="fireforce")
        return notify_fail("uΦۨ\\~ണɱC\n");
if(be+i > me->query("max_force"))
 return notify_fail("Aҭnɪ[wWLzOFC\n");
        if( i*2 > me->query("force") )
        return notify_fail("AOHC\n");
        if( i <= 0 )
        return notify_fail("A̤֭nɤ@IC\n");
        if( me->query_temp("killup")==1 )
        return notify_fail("AbB\\C\n");
        me->add("force",-i);
        message_vision(HIC + "$NB_ۨ\\ϴɱC\n" + NOR,me);
        me->start_call_out((:call_other, __FILE__, "bell_change",me,i:),2);
        me->set_temp("killup",1);
        return 1;
}
void bell_change(object me,int i)
{
    me->add("bellicosity",i);
    message_vision(YEL + "$N𴣤ɤF"+chinese_number(i)+"IC\n" + NOR,me);
    me->delete_temp("killup");
    return ;
}

int help(object me)
{
    write(@HELP
 
O榡R cmd killup <>>
 
RoӫOAiHΤO,WzO̤jȡC
      : cmd killup 10  [QI
 
HELP
);
     return 1;
}
