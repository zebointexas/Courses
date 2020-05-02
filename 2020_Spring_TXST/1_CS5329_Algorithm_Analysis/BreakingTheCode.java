import java.util.HashMap;

public class BreakingTheCode {

    public static void main(String[] args) {

        String code = "qesdfvujrockgpthzymbnxawli";
        String message = "mwiizkelza";

        String codeBK = "qesdfvujrockgpthzymbnxawli";
        String messageBK = "19242626171202251723";

        String output1 = decodingEncoding(code,message);
        String output2 = decodingEncoding(codeBK,messageBK);


        System.out.println("The output is " + output1);  // my output is 19242626171202251723
        System.out.println("The output is " + output2);  // my output is mwiizkelza

        // It is done! Final test.

    }

    public static String decodingEncoding(String code, String message){

            // prepare two hashmap to store the mapping rule
            // (from number to letter and from letter to map )
            HashMap<String, String> mapToString = new HashMap<>();
            HashMap<String, String> mapToInt = new HashMap<>();

            // to fill up the two maps according to the pattern provided by "code"
            for(int i = 0; i<26; i++){

                String letter = code.substring(i,i+1);
                String number;

                if(i<10){ // 0 - 9   -->  00, 01

                    StringBuffer sb = new StringBuffer();
                    sb.append("0").append(Integer.toString(i+1));

                    number= sb.toString();

                } else {  // 10 - 26
                    number = Integer.toString(i+1);
                }

                mapToString.putIfAbsent(number, letter);
                mapToInt.putIfAbsent(letter, number);

                        //  System.out.println("number = " + number + "   and letter = " + letter);

            }

         // check the message type: letters or numbers
            Boolean isLetter = !Character.isDigit(message.charAt(0));  // another way to validate the input String.matches(regular expression such as [0-9], etc);

            StringBuffer output = new StringBuffer();

            if(isLetter) {  // if it is letter, we need to decode into numebrs

                for(int j = 0; j < message.length(); j++){
                    String unit = message.substring(j,j+1);
                    output.append(mapToInt.get(unit));
                }

            } else {  // if it is numbers, we need to decode into letters

                for(int j = 0; j < message.length(); j++, j++){
                    String number = message.substring(j,j+2);
                    output.append(mapToString.get(number));

                }

            }

        return output.toString();
    }

}
