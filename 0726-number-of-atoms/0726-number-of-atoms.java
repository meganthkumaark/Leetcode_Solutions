
class Solution {
    public String countOfAtoms(String formula) {
        Stack<Map<String, Integer>> stack = new Stack<>();
        Map<String, Integer> current = new HashMap<>();
        int i = 0, n = formula.length();

        while (i < n) {
            char ch = formula.charAt(i);
            i++;

            if (ch == '(') {
                stack.push(current);
                current = new HashMap<>();
            } else if (ch == ')') {
                int numStart = i;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    i++;
                }
                int multiplier = numStart < i ? Integer.parseInt(formula.substring(numStart, i)) : 1;

                if (!stack.isEmpty()) {
                    Map<String, Integer> temp = current;
                    current = stack.pop();
                    for (String key : temp.keySet()) {
                        current.put(key, current.getOrDefault(key, 0) + temp.get(key) * multiplier);
                    }
                }
            } else {
                int atomStart = i - 1;
                while (i < n && Character.isLowerCase(formula.charAt(i))) {
                    i++;
                }
                String atom = formula.substring(atomStart, i);

                int numStart = i;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    i++;
                }
                int count = numStart < i ? Integer.parseInt(formula.substring(numStart, i)) : 1;

                current.put(atom, current.getOrDefault(atom, 0) + count);
            }
        }

        List<String> atoms = new ArrayList<>(current.keySet());
        Collections.sort(atoms);

        StringBuilder sb = new StringBuilder();
        for (String atom : atoms) {
            sb.append(atom);
            if (current.get(atom) > 1) {
                sb.append(current.get(atom));
            }
        }

        return sb.toString();
    }
}