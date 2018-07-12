/**
 * https://leetcode.com/problems/text-justification/description/
 * 2015/09
 * 272 ms
 */

public class Solution
{
    private String spaces[];
    private String words[];
    private ArrayList<Interval> segs;
    private List<String> lines;

    public List<String> fullJustify(String[] words, int maxWidth)
    {
        spaces = new String[maxWidth + 1];
        for(int i = 0; i <= maxWidth; i ++)
        {
            spaces[i] = new String();
            for(int count = 0; count < i; count ++)
                spaces[i] += " ";
        }
        segs = new ArrayList<Interval>();
        this.words = words;

        int begin = 0;
        int end = 0;
        int width = 0;
        while(begin < words.length)
        {
            if(end >= words.length)
            {
                segs.add(new Interval(begin, words.length - 1));
                break;
            }
            width += (words[end].length() + 1);
            if(width - maxWidth > 1)
            {
                segs.add(new Interval(begin, end - 1));
                width = 0;
                begin = end;
            }
            else
                end ++;
        }
        
        lineAlign(maxWidth);

        return lines;
    }

    private void lineAlign(int line_width)
    {
        lines = new ArrayList<String>();
        for(int idx = 0; idx < segs.size(); idx ++)
        {
            Interval seg = segs.get(idx);
            if(idx == segs.size() - 1)
            {
                String line = new String(words[seg.begin]);
                for(int i = seg.begin + 1; i <= seg.end; i ++)
                    line += (" " + words[i]);
                lines.add(line);
                break;
            }
            int words_width = 0;
            for(int i = seg.begin; i <= seg.end; i ++)
                words_width += words[i].length();
            int spaces_width = line_width - words_width;
            int num_spaces = seg.end - seg.begin;

            if(num_spaces <= 0)
            {
                lines.add(new String(words[seg.begin]));
                continue;
            }
            if(spaces_width % num_spaces == 0)
            {
                String insert_space = spaces[spaces_width / num_spaces];
                String line = new String(words[seg.begin]);
                for(int i = seg.begin + 1; i <= seg.end; i ++)
                    line += (insert_space + words[i]);
                lines.add(line);
            }
            else
            {
                int insert_width = spaces_width / num_spaces;
                int rest = spaces_width % num_spaces;
                String line = new String(words[seg.begin]);
                for(int i = 0; i + seg.begin < seg.end; i ++)
                {
                    if(i < rest)
                        line += (spaces[insert_width + 1] + words[1 + i + seg.begin]);
                    else
                        line += (spaces[insert_width] + words[1 + i + seg.begin]);
                }
                lines.add(line);
            }
        }
        for(int i = 0; i < lines.size(); i ++)
            if(lines.get(i).length() < line_width)
                lines.set(i, lines.get(i) + spaces[line_width - lines.get(i).length()]);
    }

    private class Interval
    {
        public int begin;
        public int end;
        public Interval(int begin, int end) { this.begin = begin; this.end = end; }
        public Interval() { begin = -1; end = -1; }
    }
}
