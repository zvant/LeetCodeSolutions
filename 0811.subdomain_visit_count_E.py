'''
https://leetcode.com/problems/subdomain-visit-count/description/
2018/07
52 ms
'''

class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        freqs = {}
        for domain in cpdomains:
            count, subs = domain.split(' ')
            subs = subs.split('.')
            count = int(count)
            for idx in range(0, len(subs)):
                sub_domain = '.'.join(subs[idx:len(subs)])
                if sub_domain in freqs:
                    freqs[sub_domain] += count
                else:
                    freqs[sub_domain] = count
        results = []
        for domain in freqs:
            results.append(str(freqs[domain]) + ' ' + domain)
        return results
