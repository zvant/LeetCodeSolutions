'''
https://leetcode.com/problems/encode-and-decode-tinyurl/description/
2017/03
48 ms
'''

import md5

class Codec:
    urlDict = {}
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        shortUrl = 'http://short.url/' + md5.new(longUrl).hexdigest()[0:11]
        self.urlDict[shortUrl] = longUrl
        return shortUrl

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.urlDict[shortUrl]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
