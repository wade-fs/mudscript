
// godcure.c
// 10                           ->內傷藥(health-medicine)
// 10                           ->去春丸(flower-medicine) 
// 20                           ->調氣丹(force-medicine)
// 30                           ->蛇毒的解藥(snake-medicine)
// 30                           ->火玫瑰毒的解藥(rose-medicine)
// 40                           ->外傷藥(outhealth-medicine)
// 50 十年梗樹莖(tree item)     ->碧靈丹(bilin pill)
// 50 九節菖蒲(nine item)       ->九轉金丹(nine pill)
// 50 太乙山青草(taii item)     ->太乙青冥丹(taii pill)
// 60 百年人蔘(seng item)       ->人蔘伏靈露(fulin pill)
// 70 人靈草(human item)        ->人靈丹(human pill)
// 80 地靈草(ground item)       ->雲龜破氣散(ugeposisan)
// 90 天靈草(sky item)          ->天靈散(sky pill)
//100 (天,地,靈草三草合一)      ->未定(預定是力量增強濟)
#include <ansi.h>
inherit SKILL;
mapping make = ([
	             "force": ([
		                   1:"gold stone",
		                   2:"flower iron",
                       		   3:"green stone",
		                                    ]),
         	     "health": ([]),
	             "outhealth": ([]),
	             "rose": ([]),
	             "snake": ([]),
	             "flower": ([]),
                     "fulin":([ 1:"seng item",    ]),
                     "bilin":([ 1:"tree item",    ]),
                     "nine":([ 1:"nine item",    ]),
                     "taii":([ 1:"taii item",    ]),
                     "sky":([ 1:"sky item",     ]),
                     "ugeposisan":([ 1:"ground item",  ]),
                     "human":([ 1:"human item",   ]),
                     "dragon":([ 1:"sky item",
                                1:"ground item",
                                2:"human item",   ])
               ]);

mapping make_improve = ([
                              "force" : 1,
                              "health": 1,
                              "outhealth": 1,
                              "rose"  : 1,
                              "snake" : 1,
                              "flower": 1,
                              "fulin" : 2,
                              "bilin" : 1,
                              "nine"  : 1,
                              "taii"  : 1,
                              "sky"   : 2,
                              "ugeposisan": 2,
                              "human" : 2,
                              "dragon"  : 2.5,
                         ]);

mapping make_name = ([
                              "force": "調氣丹",
	                      "health": "內傷藥",
         	              "outhealth": "外傷藥",
	                      "rose": "火玫瑰毒的解藥",
	                      "snake": "蛇毒的解藥",
	                      "flower": "去春丸",
                              "fulin":"人參茯苓露",
                              "bilin":"碧靈丹",
                              "nine":"九轉金丹",
                              "taii":"太乙青冥丹",
                              "sky":"天靈丹",
                              "ugeposisan":"雲龜破氣散",
                              "human":"人靈丹",
                              "dragon":"神龍活氣丸",
                    ]);
mapping make_need_lv = ([
                              "force" : 20,
                              "health": 10,
                              "outhealth": 40,
                              "rose"  : 30,
                              "snake" : 30,
                              "flower": 10,                              
                              "bilin" : 50,
                              "nine"  : 50,
                              "taii"  : 50,
                              "fulin" : 60,
                              "human" : 70,
                              "ugeposisan": 80,
                              "sky"   : 90,
                              "dragon": 100,
                    ]);

int valid_enable(string usage)            {
        return (usage=="cure");
        }
int valid_learn(object me)                {
        return 1;
        }
int practice_skill(object me)             {
        return notify_fail("華陀醫術只能用學的。\n");
        }
int make(object me,string name)
{
        object medicine;
        int i;
        mapping dict;
        string pstr="";
        if(!make[name])
                return notify_fail("華陀醫術中沒有這種藥耶。\n");
        if(me->query_skill("godcure",1)<make_need_lv[name])
                return  notify_fail("你的華陀醫術程度不夠﹐無法練製這種藥。\n");
        dict=make[name];
        for(i=0;i<sizeof(dict);i++)
        {
              if(!present(dict[i],me))
                return notify_fail("你的配料不足﹐無法練製。\n");
              medicine=present(dict[i],me);
              pstr+="("+medicine->name()+")";
        }
        message_vision(
        "$N用"+pstr+"來做"+make_name[name]+"。\n",me);
        for(i=0;i<sizeof(dict);i++)
                destruct(present(dict[i],me));
        for(i=0;i<5;i++)
        {
                medicine = new("obj/medicine/"+name+"_medicine");
                medicine->set("medicine_power",me->query_skill("cure")/10);
                medicine->move(me);
        }
  if(me->query_skill("godcure",1) < 100)
  {
    i = me->query_int()/3
        + make_improve[name]*(me->query_skill("cure",1)/20);
    me->improve_skill("godcure",random(i));
  }
   return 1;
}
string perform_action_file(string action) {
        return CLASS_D("doctor")+"/godcure/"+action;
        }


