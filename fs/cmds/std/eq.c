// onion 改寫過, 可以把相同的東西簡化
// wade fixed some bug, 以及減少 CPU 時間. (5/24/1996)
// fund 修改﹐配合物品數量限制 (8/15/1996)

#include <ansi.h>
#include <carry.h>

varargs int main( object me, string arg, int mode )
{
	object	ob, *inv, *tmp,obj;
	int i, j, found;
  string str;

	if( wizardp(me) ) 
	{
		if (!arg) ob = me;
		else if (arg == "here") ob = environment(me);
		if (!ob) 
		{
		  arg = lower_case(arg);
                  ob = find_player(arg);
		}
		if ( !ob ) ob = find_living(arg);
		if ( !ob ) ob = present(arg, environment(me));
		if ( !ob ) ob = me;
                if ( wiz_level(me) < wiz_level(ob) )
                return notify_fail ("沒有這個玩家。\n");
	}
	else ob = me;

	if( mode==1 )
		ob = me->query_temp("pal");

	tmp = all_inventory(ob);
	if( !sizeof(tmp) ) {
		write((ob==me)? "目前你身上沒有任何東西。\n"
			: ob->short() + "身上沒有攜帶任何東西。\n");
		return 1;
	}
	
	
	
	printf ("%s身上帶著穿著這些東西(負重 %d%%)(空間 %d%%):\n",
		(ob==me)? "你": ob->short(),
		  (int)ob->query_encumbrance() * 100
		/ (int)ob->query_max_encumbrance(),
		100 * sizeof(tmp) / MAX_CARRY );
  write("武器：\n");
  obj = ob->query_temp("weapon");
  str = "    "HIC"(手持)"NOR"武器 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj = ob->query_temp("secondary_weapon");
  str = "    "HIC"(手持)"NOR"武器 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");
  if(ob->query("class") == "blademan") {
    obj = ob->query_temp("third_weapon");
    str = "    "HIC"(嘴咬)"NOR"武器 "HIC"- "+NOR+((!obj)?"無":obj->short());
    write(str+"\n");
  }
  write("\n");
  write("裝備：\n");
  obj =  ob->query_temp("armor/head"); 
  str = "    "HIC"(頭部)"NOR"頭戴 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/neck"); 

           str = "    "HIC"(頸部)"NOR"頸戴 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/cloth"); 

         str = "    "HIC"(身體)"NOR"身穿 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

/*
  obj =  ob->query_temp("armor/armor"); 

           str = "    "HIC"(身著)"NOR"外套 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");
*/
  obj =  ob->query_temp("armor/wrists"); 

           str = "    "HIC"(手腕)"NOR"腕套 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/armbands"); 

           str = "    "HIC"(雙臂)"NOR"臂套 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/shield"); 

           str = "    "HIC"(手上)"NOR"手握 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/hands"); 

           str = "    "HIC"(雙掌)"NOR"手戴 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/finger"); 

           str = "    "HIC"(手指)"NOR"指戴 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/finger2"); 

           str = "    "HIC"(手指)"NOR"指戴 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/waist"); 

       str = "    "HIC"(腰部)"NOR"腰繫 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/leggings"); 

           str = "    "HIC"(雙腿)"NOR"腿套 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/boots"); 

           str = "    "HIC"(足部)"NOR"足蹬 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/cape"); 

           str = "    "HIC"(背披)"NOR"披著 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");

  obj =  ob->query_temp("armor/pants"); 

           str = "    "HIC"(腰下)"NOR"穿著 "HIC"- "+NOR+((!obj)?"無":obj->short());
  write(str+"\n");


	return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : inventory			<一般玩家>
	   inventory <生物或玩家名字>	<巫師專用>
	   inventory <here>		<巫師專用>
指令說明 : 
           可列出你(妳)目前身上所攜帶的所有物品。
   註    : 此指令可以 " i " 代替。
HELP
);
        return 1;
}
