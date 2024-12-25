void main() {
  // string
  var name = 'a name';

  // constant at assignment time
  final name2 = 'a name2';
  final String name3 = 'a name3';

  // constant at compile time
  const String name4 = 'a name4';
  print('name: $name');

  int aNumber = 10;
  double aDecimal = 1.0;
  print('$aDecimal, $aNumber');

  bool aBoolean = true;
  print(aBoolean);
  print(!aBoolean);

  bool? nullableBoolean = null;
  print(nullableBoolean);

  List<String> names = ['peter', 'tony'];
  print(names);

  names.add('jane');
  print(names);
  print(names[2]);

  List<dynamic> objects = [1, 'hello'];
  print(objects);

  Map<String, String> person = {
    'name': 'jack',
    'last': 'sparrow',
  };
  print(person);
  print(person['name']);
}
