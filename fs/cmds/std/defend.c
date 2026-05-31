#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
  object obj;
  int i,done,flag;
  if (!str)                         //不加參數時為查詢
  {
    if (!sizeof(me->query_temp("defend"))&&!sizeof(me->query_temp("defend_by"))) 
    {
      write("你現在沒有保護任何人\n");
      return 1;
    }
    if ( !sizeof(me->query_temp("defend_by")) )
    {  
      write("你現在掩護著：\n");
      for(i=0;i < sizeof(me->query_temp("defend"));i++)
      {                        //先濾掉己經不存在的人,如己經離線者
                               //或是己經被做了的NPC
                               //實際上這個應該寫成函數的因為這在程式中
                               //時常出現，幾乎只要下defend命令就會先過濾
                               //一次，不過因為當初寫的時侯沒注意到所以
                               //在程式中有好幾個類似這樣的過濾程式
                               //不過功能都一樣
        if(!find_living(me->query_temp("defend/"+(string)i)))
        {
          me->set_temp("defend/"+(string)i,
          me->query_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1)));
          me->delete_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1));
          i--;                
        }       
      }
      for (i=0;i < sizeof(me->query_temp("defend"));i++) 
        write((me->query_temp("defend/"+(string)i))+"\n"); 
      return 1;
    }
    else
    {
      write("現在掩護你的人有：\n");
      for(i=0;i < sizeof(me->query_temp("defend_by"));i++)
      {                               //過濾程式
        if(!find_living(me->query_temp("defend_by/"+(string)i)))
        {
          me->set_temp("defend_by/"+(string)i,
          me->query_temp("defend_by/"+(string)(sizeof(me->query_temp("defend_by"))-1)));
          me->delete_temp("defend_by/"+(string)(sizeof(me->query_temp("defend_by"))-1));
          i--;                
        }       
      }
      for (i=0;i < sizeof(me->query_temp("defend_by"));i++) 
        write((me->query_temp("defend_by/"+(string)i))+"\n");
      return 1;
    }   
  }
           //以下為判斷是否為有效的保護關係.
           //保護關係成立的基本設定:
           //1.保護者與被保護者必需同時在場且均active
           //2.被保護者不能是自己或是非生物
           //3.保護關係只能有兩層，意即如果自己已經被保護則不能再保護他人
           //  而且也不能保護已經保護他人的使用者
           //4.死亡後保護關係自動解除
  if (!objectp(obj = present(lower_case(str), environment(me))))
    return notify_fail("這裡沒這個人。\n");
  str = lower_case(str);
  if( !obj->is_character() )
    return notify_fail("那不是生物不需要掩護。\n");
  if(obj==me) return notify_fail("要保護自己就趕快練功\吧^_^.\n");
  if(1 || userp(obj)) 
  {
    if (sizeof(me->query_temp("defend_by"))) 
      return notify_fail("你自己都被人保護了還想保護別人？\n");
    if (sizeof(obj->query_temp("defend")))
      return notify_fail("他似乎不需要你的保護。\n");
    for(i=0;i < sizeof(me->query_temp("defend"));i++)
    {
      if(str == me->query_temp("defend/"+(string)i)) done++;
      if(!find_living(me->query_temp("defend/"+(string)i)))
      {                      //過濾程式
        me->set_temp("defend/"+(string)i,
        me->query_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1)));
        me->delete_temp("defend/"+(string)(sizeof(me->query_temp("defend"))-1));
        i--;                
      }
    }
    if (!done) me->set_temp("defend/"+(string)i,str);
    else flag=1;
    for(i=0,done=0;i < sizeof(obj->query_temp("defend_by"));i++)
    {
      if(me->query("id") == obj->query_temp("defend_by/"+(string)i)) done++;    
      if(!find_living(obj->query_temp("defend_by/"+(string)i)))
      {                      //過濾程式
        obj->set_temp("defend_by/"+(string)i,
        obj->query_temp("defend_by/"+(string)(sizeof(obj->query_temp("defend_by"))-1)));
        obj->delete_temp("defend_by/"+(string)(sizeof(obj->query_temp("defend_by"))-1));
        i--;                
      }       
    }
    if (done && flag) return notify_fail("你己經在保護他了不是嗎？\n"); 
    if (!done) obj->set_temp("defend_by/"+(string)i,me->query("id"));
    message_vision("\n$N移動到$n前面掩護$p。\n", me, obj ,obj);
  }
  return 1;
}

int help(object me)
{
  write(@HELP
  指令格式 : defend <人物>
  
      這個指令讓你在戰鬥中掩護他人，掩護的效果決定於你的膽識(cor)與
  基本拆招卸力(parry)的技巧。當掩護成功的時，所有對於被掩護者的攻擊
  都將轉嫁到你身上。在戰鬥中掩護他人時，你的閃躲空間將會受到大幅的影
  響，阻擋的能力也有些許的限制。所以如果你的技巧不夠成熟而強行硬擋的
  話，將可能使自己在戰鬥中陷入險境。不過老練的武者卻常以保護他人來訓
  練自己，在艱難戰鬥中獲得更多的實戰經驗。
      另外，defend只能掩護戰術上的攻擊。對於戰略上的攻擊：如咒語，法
  術，特殊招式......等等效果不彰。
  
  其他相關指令: undefend
  
HELP);
  return 1;
}
              
