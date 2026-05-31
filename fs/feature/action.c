// action.c
#include <ansi.h>
static mixed busy, interrupt;

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
  object me, attacker , *obs;
  string uuid;

	if( !new_busy ) return;
	if( !intp(new_busy) && !functionp(new_busy) )
    error("action: Invalid busy action type.\n");

  me = this_object();
  if( me->query("quests/confused") && me->query_temp("confused"))// 解過迷
  {
    obs = previous_object(-1);
    if(sizeof(obs))
    {
      foreach(object at in obs)
      {
        if(at->is_character()) {
          attacker = at;
          break;
        }
      }
    }
    if(!attacker && sizeof(obs))
      attacker = previous_object(-1)[<1];
    if(!attacker)
      attacker = me;
    if(!attacker->is_character() && environment(attacker))
      attacker = environment(attacker);

    uuid = explode(file_name(me),"/")[<1];


    //  tell_object(find_player("whatup"),sprintf("me=%O\n,attack=%O\nuuid=%s\n",me,attacker,uuid));
    if(me != attacker && // 別人觸發才有用
        // 這樣要檢查有沒有運
        !attacker->query_temp("busy/"+uuid) // 沒解過穴
      )
    {
      attacker->set_temp("busy/"+uuid,1);
      message_vision(GRN"$n一個手忙腳亂，竟然中了$N的「拋磚引玉」之計，封鎖錯了穴道。\n"NOR,me,attacker);
      return ;
    }

  }
	if (intp(busy) && intp(new_busy))
	  busy += new_busy;
	else
	  busy = new_busy;
	if( !intp(new_interrupt) && !functionp(new_interrupt) )
		error("action: Invalid busy action interrupt handler type.\n");
  
	interrupt = new_interrupt;
	set_heart_beat(1);
}

nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy!=0; }

// This is called by heart_beat() instead of attack() when a ppl is busy
// doing something else.
/* private */ void continue_action()
{
	if( intp(busy) && (busy > 0) ) {
    int sk =  this_object()->query_skill("acupuncture",1) ;

		busy--;
    // check have skills ? 解迷沒？ skill 高低 
    if( busy != 0 &&
        this_object()->query("quests/acupuncture") &&
        random(200*sk) < sk*sk  && 
        this_object()->is_fighting() && 
        this_object()->query("env/衝穴") &&
        this_object()->query("force") > 2000)
    {
      int rand;
      string family;
      family = this_object()->query("family/family_name");
      rand = 0;
      switch(family)
      {
        case "段家":
          rand = random( sk/25 ) + 1;
          break;
        case "銀針門":
          rand = random( sk/20 ) + 1;
          break;
        case "冥蠱魔教":
          rand = random( sk/30 ) + 1 ;
          break;
        default:
        // 其他門派不會衝穴 
        return ;
      }
      if(rand == 0) return ;
      if(rand > busy) rand = busy;
      
      message_vision(HIW"$N衝開了身上"+CHINESE_D->chinese_number(rand)+"處的穴道，但還有數個穴道被封鎖住。\n"NOR,this_object());
      if(random(5) == 0)
        this_object()->improve_skill("acupuncture",1);
      this_object()->add("force",-300);
      busy -= rand;
    }
		return;
	} else if( functionp(busy) ) {
		if( !evaluate(busy, this_object()) ) {
			busy = 0;
			interrupt = 0;
		}
	} else {
		busy = 0;
		interrupt = 0;
	}
}

void delete_busy()
{
	if( !busy || !interrupt ) {
            busy = 0;
	    interrupt = 0;
	}
} 

void interrupt_me(object who, string how)
{
	if( !busy ) return;

	if( intp(busy) && intp(interrupt) ) {
		if( busy < interrupt ) busy = 0;
	} else if( functionp(interrupt) ) {
		if( evaluate(interrupt, this_object(), who, how) ) {
			busy = 0;
			interrupt = 0;
		}
	}
}

// This function is for temporary conditions's recovery call_outs, bcz
// such recovery function call_out might be destroyed if some wizard
// destructed the object that is reponsible of it, so we let users launch
// the call_out themself. Thus we can make sure the recovery call_out.
// 
// Because this could cause a serious security problem, so we need highest
// security check here.
int start_call_out(function fun, int delay)
{
	if( !previous_object()
	||  (geteuid(previous_object()) != ROOT_UID
	     && userp(this_object())
	     && this_player(1) != this_object()))
		return 0;

	call_out("eval_function", delay, fun);
	return 1;
}

/* private */ void eval_function(function fun) { evaluate(fun); }
