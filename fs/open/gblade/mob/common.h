
void heart_beat()
{
  if(!environment()) return ;
  if(!this_object()->is_fighting()) {
    message_vision(HIW"一陣煙霧環繞在$N的元神身上，$N的元神就突然消失了。\n"NOR,this_object());
    destruct(this_object());
    return ;
  }
  ::heart_beat();
}
