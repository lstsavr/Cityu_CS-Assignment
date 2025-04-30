# Input the email with your keyboard #
email = input('Please enter the test Email: ')     # gets the test email
email = email.lower()                              # convert string to lowercase
print(email)

# Input the spam detection keyword #
word1 = input('Please enter the first key word: ') # gets the first keyword
word1 = word1.lower()                              # convert the first key word to lowercase

word2 = ____________                               # gets the second keyword
word2 = word2.lower()                              # convert the second keyword to lowercase

word3 = ____________                               # gets the third keyword
word3 = word3.lower()                              # convert the third keyword to lowercase

word4 = ____________                               # gets the fourth keyword
word4 = word4.lower()                              # convert the fourth keyword to lowercase

word5 = ____________                               # gets the fifth keyword
word5 = word5.lower()                              # convert the fifth keyword to lowercase

# Detect whether the key word occured in your email #
n_word1 = email.count(word1)  # count the number of the first keyword in the email
n_word2 = email.count(word2)  # count the number of the second keyword in the email
n_word3 = email.count(word3)  # count the number of the third keyword in the email
n_word4 = email.count(word4)  # count the number of the fourth keyword in the email
n_word5 = email.count(word5)  # count the number of the fifth keyword in the email

# The prior odds of spam is 80% #
p_spam = 1.0                                         # initialize the likelihood ratio of the spam email
p_no_spam = 1.0                                      # initialize the likelihood ratio of the no spam email
prior_odds_spam = ____________                       # prior odds of spam

# Calculate the Likelihood ratio #
if n_word1 != 0:                                     # the first keyword occurred in the email
    p_spam = p_spam * 0.88
    p_no_spam = p_no_spam * 0.47
if n_word2 != 0:                                     # the second keyword occurred in the email
    p_spam = ____________
    p_no_spam = ____________
if n_word3 != 0:                                     # the third keyword occurred in the email
    p_spam = ____________
    p_no_spam = ____________
if n_word4 != 0:                                     # the fourth keyword occurred in the email
    p_spam = ____________
    p_no_spam = ____________
if n_word5 != 0:                                     # the fifth keyword occurred in the email
    p_spam = ____________
    p_no_spam = ____________

# Calculate the Posterior odds #
posterior_odds_spam = ____________                   # posterior odds of spam
posterior_odds_no_spam = ____________                # posterior odds of no spam

p_isSpam = ____________                              # probability of spam P(spam | email)

print("p_spam: %.6f, p_no_spam: %.6f, posterior_odds_spam: %.6f, posterior_odds_no_spam: %.6f, p_isSpam: %.6f"%(p_spam, p_no_spam, posterior_odds_spam, posterior_odds_no_spam, p_isSpam))


