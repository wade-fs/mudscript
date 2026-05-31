#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int skl;
int fk;
int conjure (object me, object target)
{       string msg;
fun=me->query("spells/dreamcure/level");
skl = (int)(me->query_skill("dremagic", 1));
fk=(fun+skl)/2;
if (!me->query("spells/dreamcure/level"))
     return 0;

if(me->query_temp("dreamcure")==1)
return notify_fail("你正在施法。\n");
        if( (int)me->query("atman")< 80 )
                return notify_fail("你的靈力不夠。\n"); 
        if(me->query("class") != "dancer")
                return notify_fail("只有舞者才能使用。\n");
       me->set_temp("dreamcure",1);
       if(!target)
       {
                message_vision(HIG"$N使出了夢玄法鑑中的"HIC"治療術"HIG"﹐只見一陣神奇光芒籠照全身。\n"NOR, me);
       call_out("act1",3,msg,target,me,fun,fk);
       return 1;
        }
        else{
                message_vision("[32m$N使出了夢玄法鑑中的[37m治療術[32m﹐幫$n療傷只見一陣神奇光芒籠照$n全身。[0m\n", me, target);
                call_out("act2",3,msg,target,me,fun,fk);
                return 1;
        }

}
int act1(string msg,object target,object me,int fun,int fk) {
if(!me) return 1;
if(fk<40){
         message_vision("[32m$N在神光籠罩下復原了少許\！[0m\n", me);
         me->receive_curing("kee", fk+150 );
}else if(fk>=41&&fk<=80){
         message_vision("[32m$N在神光籠罩下明顯的好了許\多！[0m\n", me);
         me->receive_curing("kee", fk*2+150 );
}else if(fk>=81&&fk<=99){
         message_vision("[32m$N在神光籠罩下已經痊癒了大半！[0m\n", me);
         me->receive_curing("kee", fk*3+150 );
}else if(fk>=100){
         message_vision("[32m$N在神光籠罩下幾乎完全的復原了！[0m\n", me);
         me->receive_curing("kee", fk*3+250 );
}
         me->add("atman",-80);
         me->delete_temp("dreamcure");
  if(fun<100) spell_improved("dreamcure",random(1000));
         return 1;
}
int act2(string msg,object target,object me,int fun,int fk) {
         message_vision("[32m$p在神光籠罩下漸漸的復原了！[0m\n", me, target);
         fk = fk/2;
        if(target)
         target->receive_curing("kee", fk+100 );
        if(me){

         me->add("atman",-80);
         me->delete_temp("dreamcure");
  if(fun<100) spell_improved("dreamcure",random(1000));
        }
         return 1;
}
