//陰魂不散
//必需經由特別方式才能解除的狀態之一

#include <ansi.h>

int update_condition(object me, int duration)
{
  object ob1,ob2;
  if( !me || !environment(me) ) return 1;
  seteuid(getuid());
  ob1=new("/open/magic-manor/ghost/condition/c-ghost");
  ob2=new("/open/magic-manor/ghost/condition/c-ghost");

  if( duration >= 15 )
  {
    if( random(100) > 75 )
    {
      tell_object(me,HIB"\n數道陰魂由地底竄起並朝著這邊飛了過來，嚇的你一時措手不及!!\n"NOR);
      message("vision",me->name() + "陰魂纏身，好像做了什麼虧心事似的，引來厲鬼報復。\n"NOR,environment(me), me);
      ob1->move(environment(me));
      ob1->kill_ob(me);
      ob1->set_leader(me);
      ob2->move(environment(me));
      ob2->kill_ob(me);
    } else {
      message_vision(HIB"$N的後面好像有什麼東西在跟著，令人心頭為之一寒!!\n"NOR,me);
    }
  }
  else if( duration >= 1 )
  {
    if ( random(100) > 75 )
    {
      tell_object(me,HIB"\n一道陰魂由地底竄起並朝著這邊飛了過來，嚇的"+gender_self(me->query("gender"))+"一時措手不及!!\n"NOR);
      message("vision",me->name() + "陰魂纏身，好像做了什麼虧心事似的，引來厲鬼報復。\n"NOR,environment(me), me);
      ob1->move(environment(me));
      ob1->kill_ob(me);
    } else {
      message_vision(HIB"$N的後面好像有什麼東西在跟著，令人心頭為之一寒!!\n"NOR,me);
    }
  }
  if( duration < 1 )
    return 0;
  return 1;
}
